process.stdin.resume();
process.stdin.setEncoding('ascii');


textInput = "";
process.stdin.on('data', function (input) {
    textInput += input;
});


process.stdin.on('end', function () {
    processData(textInput);
});



function processData(input) {
    var repeatedNumbers = {};
    var lines = input.split('\n');
    var numbers = lines[1].split(' ').map(function (val) {
        return parseInt(val);
    });

    if (numbers.length == 1) {
        process.stdout.write(numbers[0].toString());
    } else {
        numbers.sort();
        for (var i = 0; i < numbers.length - 1; i++) {
            if (numbers[i] == numbers[i + 1]) {
                repeatedNumbers[numbers[i]] = true;
            }
        }

        numbers.forEach(function (number) {
            if (repeatedNumbers[number] != true)
                process.stdout.write(number.toString() + '\n');
        });
    }
}