
import Vue from 'vue';
import App from './app.vue';
import Key from './key.vue';
import SrcKey from './srckey.vue';

Vue.component('app', App);
Vue.component('key', Key);
Vue.component('srckey', SrcKey);

new Vue({
	el: '#app',
	render: x => x(App)
});

