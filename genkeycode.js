let fs = require('fs');

let src = fs.readFileSync('./keycode.txt').toString();

// console.log(src);

let str = '';

str += '#ifndef __INCLUDED_KEYCODE_H__\r\n';
str += '#define __INCLUDED_KEYCODE_H__\r\n';
str += '\r\n';

src.split(/\n/).forEach(function(line) {
	let values = line.split(/\t/);
	// console.log(values);
	let code = values[1];
	let name = values[2];
	str += `#define ${name} ${code}\r\n`;
});

str += '\r\n';
str += '#endif\r\n';

fs.writeFile('./keycode.h', str, function(err) {
	if (err) console.error(err);
});

