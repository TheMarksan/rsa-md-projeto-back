import express from "express";
import dotenv from "dotenv";
import cors from "cors";
import router from "./routes/test.cjs";

dotenv.config();

const app = express();
app.use(express.json());
app.use(cors());
app.use(router);

const PORT = 4000 || process.env.PORT;
app.listen(PORT, () => {
  console.log(`Server running on port: ${PORT}`);
});