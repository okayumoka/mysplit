
import Vue from 'vue';
import App from './app.vue';
import Key from './key.vue';

Vue.component('app', App);
Vue.component('key', Key);

new Vue({
	el: '#app',
	render: x => x(App)
});

