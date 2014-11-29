# userinfo

[![Current Version](https://img.shields.io/npm/v/userinfo.svg)](https://www.npmjs.org/package/userinfo)
[![Build Status via Travis CI](https://travis-ci.org/cjihrig/userinfo.svg?branch=master)](https://travis-ci.org/cjihrig/userinfo)
![Dependencies](http://img.shields.io/david/cjihrig/userinfo.svg)
![devDependencies](http://img.shields.io/david/dev/cjihrig/userinfo.svg)

Node.js native addon for working with user information

## Methods

### `whoami()`

  - Arguments
    - None
  - Returns
    - string - The current username.

Returns the current username. Calls `GetUserName()` on Windows, and `getlogin_r()` otherwise. Throws if the username cannot be retrieved.

### `getHomeDirectory()`

  - Arguments
    - None
  - Returns
    - string - The current user's home directory.

Returns the current user's home directory. Calls `SHGetKnownFolderPath()` on Windows, and `getlogin_r()` followed by `getpwnam()` otherwise. Throws if the home directory cannot be retrieved.

## Command Line Interface (CLI)

userinfo functionality can be accessed via the command line. The CLI is available using the `userinfo` command. The following command line arguments are valid:

  - `w`, `whoami` - Invokes `whoami()`
  - `H`, `getHomeDirectory` - Invokes `getHomeDirectory()`
