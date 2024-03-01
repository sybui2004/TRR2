// ==UserScript==
// @name         Moodle thay thang New
// @version      3/1/2024
// @match http://*.drnguyenttvpl.site//*
// @description  Moodle thay thang
// @author       quochungcyou
// @run-at      document-start
// @license MIT
// @include http://*drnguyenttvpl.site/*

// ==/UserScript==
(function() {
    'use strict';

    function doSomething() {

        var allowPaste = function(e) {
            e.stopImmediatePropagation();
            return true;
        };

        document.addEventListener('paste', allowPaste, true);


    }
    setInterval(doSomething, 1500);
})();