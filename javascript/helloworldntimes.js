process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
    processData(parseInt(_input));
});



function processData(input) {
    for (var i = 0; i < input; i++)
        process.stdout.write("Hello World" + '\n');
}