import express from "express";
import dotenv from "dotenv";
import cors from "cors";
import chavePubRouter from "./routes/chavePub.cjs";
import desencriptarRouter from "./routes/desencriptar.cjs";
import encriptarRouter from "./routes/encriptar.cjs";

dotenv.config();

const app = express();
app.use(express.json());
app.use(cors());
app.use(chavePubRouter);
app.use(desencriptarRouter);
app.use(encriptarRouter);
app.get("/health", async (req,res) => {
  res.sendStatus(200);
})

const PORT = 4000;
app.listen(PORT, () => {
  console.log(`Server running on port: ${PORT}`);
});

export default app;
