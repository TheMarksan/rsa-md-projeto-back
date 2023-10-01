{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "desencriptar.cpp"
      ],
      "include_dirs": [
        "/path/to/gmp/include" 
      ],
      "libraries": [
        "-L/path/to/gmp/lib",  
        "-lgmp"
      ],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "xcode_settings": {
        "OTHER_CFLAGS": ["-fno-exceptions"],
        "GCC_ENABLE_CPP_EXCEPTIONS": "NO"
      }
    }
  ]
}
