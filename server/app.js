const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');
const arduino = require('./arduinoConexion');
const app = express();

app.use(bodyParser.urlencoded({extended:false}));
app.use(bodyParser.json());

//prevent cors errors 
app.use(cors());

arduino.read();

module.exports = app;