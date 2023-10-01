{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "desencriptar.cpp"
      ],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "defines": ["NAPI_CPP_EXCEPTIONS"],
      "xcode_settings": {
        "OTHER_CFLAGS": ["-fno-exceptions"],
        "GCC_ENABLE_CPP_EXCEPTIONS": "NO"
      }
    }
  ]
}
