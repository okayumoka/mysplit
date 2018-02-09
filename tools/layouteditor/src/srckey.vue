
<template>
	<div :class="className">
		{{name}}
	</div>
</template>

<style>
.srckey{
	width: 50px;
	height: 50px;
	line-height: 50px;
	font-size: 12px;
	font-family: 'Consolas';
	display: inline-block;
	border: solid 1px red;
	text-align: center;
	margin-right: 5px;
	margin-bottom: 5px;
	overflow: hidden;
}
.srckey.BS { width: 142px; }
.srckey.Tab { width: 80px; }
.srckey.Caps { width: 102px; }
.srckey.LShift { width: 134px; }
</style>

<script>
module.exports = {
	props: [ 'name', 'keycode' ],
	data: function() {
		return {
			className: 'srckey'
		}
	},
	created: function() {
		console.log(this.keyCode);
		this.className = 'srckey ' + this.name;
	},
	methods: {
	},
};
</script>


