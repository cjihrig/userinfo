'use strict';
var Fs = require('fs');
var Code = require('code');
var Lab = require('lab');
var UserInfo = require('../');

var lab = exports.lab = Lab.script();
var expect = Code.expect;
var describe = lab.describe;
var it = lab.it;

describe('UserInfo', function () {
  describe('whoami()', function () {
    it('returns the current username', function (done) {
      var user;

      expect(function () {
        user = UserInfo.whoami();
      }).not.to.throw();

      expect(user).to.be.a.string();
      expect(user.length).to.be.greaterThan(0);
      done();
    });
  });

  describe('getHomeDirectory()', function () {
    it('returns the current user\'s home directory', function (done) {
      expect(function () {
        var home = UserInfo.getHomeDirectory();

        expect(home).to.be.a.string();
        expect(Fs.statSync(home).isDirectory()).to.be.true();
      }).not.to.throw();

      done();
    });
  });
});
