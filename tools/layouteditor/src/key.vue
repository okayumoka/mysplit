
<template>
	<div class="key">
		Return
	</div>
</template>

<style>
.key {
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
}
</style>

<script>
module.exports = {
	props: [ 'keyCode' ],
	data: function() {
		return {
		}
	},
	created: function() {
		console.log(this.keyCode);
	},
	methods: {
	},
};
</script>


