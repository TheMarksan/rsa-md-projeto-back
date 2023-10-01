const express = require("express");
const addon = require("../c functions/chavePub/build/Release/addon.node");

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

  if(result == 1){
    res.send(`Chave Pública: (${p * q},${e})`).status(200);
  }else if(result == 2){
    res.send("O expoente não é relativamente primo a n.").status(400);
  }else if(result == 3){
    res.send("q não é primo.").status(400);
  }else if(result == 4){
    res.send("p não é primo.").status(400);
  }else if(result == 5){
    res.send("p q q devem ser maiores que 10, para evitar que o bloco ASCII não ser maior que n.").status(400);
  }

  if (result) {
    res.send(`Chave Pública: (${p * q},${e})`).status(200);
  } else {
    res.send("Tá errado, my darling.").status(400);
  }
});

module.exports = router;
