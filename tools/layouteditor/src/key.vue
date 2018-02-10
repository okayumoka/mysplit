
<template>
	<div class="key" @click="onClick">
		<div>
			{{name}}
		</div>
	</div>
</template>

<style>
.key {
	display: inline-block;
	position: relative;
	width: 54px;
	height: 54px;	
	margin: 0;
	cursor: pointer;
}
.key div {
	display: inline-block;
	position: absolute;
	top: 2px;
	right: 2px;
	bottom: 2px;
	left: 2px;
	line-height: 50px;
	border: solid 1px gray;
	text-align: center;
	overflow: hidden;
	font-size: 12px;
	font-family: 'Consolas';
	background: white;
}
</style>

<script>
module.exports = {
	props: [ ],
	data: function() {
		return {
			name: '----',
			keyCode: null,
		}
	},
	created: function() {
		// console.log(this.keyCode);
	},
	methods: {
		onClick: function() {
			this.$emit('onclick', this);
		},
	},
};
</script>


