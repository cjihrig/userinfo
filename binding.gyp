{
  "targets": [
    {
      "target_name": "userinfo",
      "win_delay_load_hook": "false",
      "sources": [
        "src/userinfo.cc"
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"],
      "conditions": [
        ["OS=='win'",
          {
            "sources": [
              "src/win.cc"
            ]
          }
        ],
        ["OS!='win'",
          {
            "sources": [
              "src/unix.cc"
            ]
          }
        ]
      ]
    }
  ]
}
