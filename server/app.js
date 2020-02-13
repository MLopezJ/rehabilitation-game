const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');
const app = express();


app.use(bodyParser.urlencoded({extended:false}));
app.use(bodyParser.json());
app.use(express.static('../client/'));

//prevent cors errors 
app.use(cors());

app.get('/', function(req, res){
    res.sendFile('../client/' + '/index.html');
});

module.exports = app;