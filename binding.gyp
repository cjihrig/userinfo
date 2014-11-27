{
  "targets": [
    {
      "target_name": "userinfo",
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
