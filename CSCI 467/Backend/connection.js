var mysql = require('mysql')

var connection = mysql.createConnection({
    host: 'er7lx9km02rjyf3n.cbetxkdyhwsb.us-east-1.rds.amazonaws.com',
    user: 'rs0czd6o8w8e8r3j',
    password: 'w1ffboir25orrcs4',
    port: '3306',
    database: 'b25oudnru9u3blk4',
    multipleStatements: true
})

var conn_succ = false;

connection.connect(function(err) {
    if (err) {
        console.log(err)
        conn_succ = false;
        console.log("Error connecting to database");
        return;
    }
    conn_succ = true;
    console.log("Connected to database");
    
})

module.exports = connection