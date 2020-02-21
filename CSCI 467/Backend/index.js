const express = require('express')
var app = express()
const port = 8080

var cors = require('cors')

app.use(cors());

var usersroutes = require('./routes/customer')
usersroutes(app);

app.listen(port, (err) => {
    console.log('server is listening on port 8080');
})