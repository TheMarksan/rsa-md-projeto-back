const express = require("express");
const addon = require("../c functions/desencriptar/build/Release/addon.node");
const fs = require('fs'), path = require('path').resolve("./");


const desencriptarRouter = express.Router();

desencriptarRouter.post("/desencriptar", async (req, res) => {

    const {encryptedStr, p, q ,e} = req.body;
    const encrypted = encryptedStr.split(" ").map(e => Number(e));
    
    addon.desencriptarCpp(encrypted, Number(p), Number(q), Number(e), encrypted.length);

    const filePath = path + "/desencriptado.txt"


    fs.readFile(filePath, "utf8",(err, data) => {
        if (err) {
          console.error(err);
          res.send(err).status(403)
          return;
        }
        res.send(data).status(200)
      });

})

module.exports = desencriptarRouter;