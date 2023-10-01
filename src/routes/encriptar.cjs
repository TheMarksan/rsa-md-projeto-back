const express = require("express");
const addon = require("../c functions/encriptar/build/Release/addon.node");
const fs = require("fs"),
  path = require("path").resolve("./");

const encriptarRouter = express.Router();

encriptarRouter.post("/encriptar", async (req, res) => {
  const { message, n, e } = req.body;

  addon.encriptarCpp(message, Number(n), Number(e));

  const filePath = path + "/encriptado.txt";

  fs.readFile(filePath, "utf8",(err, data) => {
    if (err) {
      console.error(err);
      res.send(err).status(403);
      return;
    }
    res.send(data).status(200);
  });
});

module.exports = encriptarRouter;