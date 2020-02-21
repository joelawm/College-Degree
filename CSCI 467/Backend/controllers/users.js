var connection = require('../connection')


exports.get_all_users = function(req,res) {
    let stmt = 'select * from customers'
    connection.query(stmt, (err, results, fields) => {
        if (err) {
            console.log(err)
        }
        res.send(results)
    })
}