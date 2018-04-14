module.exports = {
	entry: {
		js: './src/layouteditor.js'
	},
	output: {
		filename: './dist/layouteditor.js'
	},
	module: {
		loaders: [
			{
				test: /\.vue$/,
				loader: 'vue-loader'
			}
		]
	}
};


