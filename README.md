# userinfo

Node.js native addon for working with user information

## Methods

### `whoami()`

  - Arguments
    - None
  - Returns
    - string - The current username.

Returns the current username. Calls `GetUserName()` on Windows, and `getlogin_r()` otherwise. Throws if the username cannot be retrieved.
