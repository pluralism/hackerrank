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
    var originalKey = "";
    var lines = input.split('\n');
    var firstLine = lines[0].split(' ');
    var N = parseInt(firstLine[0]);
    var K = parseInt(firstLine[1]);
    var encryptedString = lines[1];
    var current = 0;


    //N is the length of the original message
    for (var i = 0; i < N; i++) {
        current ^= parseInt(encryptedString[i]);
        if (i >= K)
            current ^= parseInt(originalKey[i - K]);
        originalKey += current.toString();
        current = parseInt(encryptedString[i]);
    }


    process.stdout.write(originalKey + '\n');
}