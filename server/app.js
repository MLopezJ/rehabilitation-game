const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');
const app = express();

app.use(bodyParser.urlencoded({extended:false}));
app.use(bodyParser.json());

//prevent cors errors 
app.use(cors());

app.get('/', function(req, res){
    res.sendFile('rehabilitation-game/client' + '/index.html');
});

module.exports = app;