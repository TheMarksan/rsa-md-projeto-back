const express = require("express");
const addon = require("../c functions/chavePub/build/Release/addon.node");
const fs = require('fs'), path = require('path').resolve("./");


const chavePubRouter = express.Router();

chavePubRouter.post("/public-key", async (req, res) => {
  const { pqe } = req.body;

  const arr = pqe.split(" ").map((e) => Number(e));
  const p = arr[0];
  const q = arr[1];
  const e = arr[2];

  const result = addon.chavePubCpp(Number(p), Number(q), Number(e));

  if(result == 1){
    const filePath = path + "/chave-publica.txt";
    fs.readFile(filePath, "utf8",(err, data) => {
      if (err) {
        console.error(err);
        res.send(err).status(403)
        return;
      }
      res.send(data).status(200)
    });

    //res.send(`(${p * q},${e})`).status(200);
  }else if(result == 2){
    res.send("O expoente não é relativamente primo a n.").status(400);
  }else if(result == 3){
    res.send("q não é primo.").status(400);
  }else if(result == 4){
    res.send("p não é primo.").status(400);
  }else if(result == 5){
    res.send("p q q devem ser maiores que 10, para evitar que o bloco ASCII não ser maior que n.").status(400);
  }
  return;
});

module.exports = chavePubRouter;
