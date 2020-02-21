module.exports = function(app) {

    const users = require('../controllers/users')
    app.route('/users')
    .get(users.get_all_users)
}