let fs = require('fs');

let src = fs.readFileSync('./keycode.txt').toString();

let str = '';

str += '#ifndef __INCLUDED_KEYCODE_H__\r\n';
str += '#define __INCLUDED_KEYCODE_H__\r\n';
str += '\r\n';

src.split(/\r\n/).forEach(function(line) {
	if (line == null ||  line == '') return;
	let values = line.split(/\t/);
	// console.log(values);
	let code = values[0];
	let name = values[1];
	str += `#define ${name} ${code}\r\n`;
});

str += '\r\n';
str += '#endif\r\n';

fs.writeFile('./keycode.h', str, function(err) {
	if (err) console.error(err);
});

