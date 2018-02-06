process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";


process.stdin.on("data", function (input) {
    _input += input;
});


process.stdin.on("end", function () {
    processData(_input);
});


function processData(input) {
    var numbersCounter = {};
    var lines = _input.split('\n');
    var n = parseInt(lines[0]);
    var numbers = lines[1].split(' ');

    for (var i = 0; i < n; i++)
        numbersCounter[numbers[i]] = numbersCounter[numbers[i]] !== undefined ? numbersCounter[numbers[i]] + 1 : 1;

    for (var i = 0; i < 100; i++)
        process.stdout.write(numbersCounter[i] !== undefined ? numbersCounter[i] + ' ' : 0 + ' ');
}