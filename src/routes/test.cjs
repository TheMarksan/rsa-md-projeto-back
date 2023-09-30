const express = require("express");
const addon = require("../../c functions/build/Release/addon");

const router = express.Router();

router.post("/test", async (req, res) => {
  const { pqe } = req.body;

  const arr = pqe.split(" ").map((e) => Number(e));
  const p = arr[0];
  const q = arr[1];
  const e = arr[2];

  /*
  const p = 11;
    const q = 13;
    const e = 7; */

  const result = addon.chavePubCpp(Number(p), Number(q), Number(e));

  if (result) {
    res.send(`Chave Pública: (${p * q},${e})`).status(200);
  } else {
    res.send("Tá errado, my darling.").status(400);
  }
});

module.exports = router;
