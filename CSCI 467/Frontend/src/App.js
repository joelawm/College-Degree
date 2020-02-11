import React, { Component } from "react";
import Navbar from "./components/Nav";
import { BrowserRouter as Router, Switch, Route, Link } from "react-router-dom";
import Admin from './components/Admin';
import CreateOrders from './components/CreateOrders';
import InHouse from './components/InHouse';
import QuoteSystem from './components/QuoteSystem';
import Login from './components/Login'
import { connect } from "react-redux";
import Welcome from './components/Welcome';
import { getPageLoad, getAssociates } from './actions/actions';



class App extends Component {

  logout() {
    this.props.dispatch({
      type: "DENY"
    });
  }
  componentDidMount() {
    this.props.getPageLoad();
    this.props.getAssociates();
  }
  
  render() {
    console.log(this.props.quotes);

    return (
      <React.Fragment>

        {this.props.auth ?

          <React.Fragment>

            <Router>
              <div>
                <nav className="navbar navbar-expand-lg navbar-light bg-light ">
                  <ul className="navbar-nav mr-auto">
                    <li><Link to={'/'} className="nav-link">Home</Link></li>
                    <li><Link to={'/quotesystem'} className="nav-link"> Quote System </Link></li>
                    <li><Link to={'/inhouse'} className="nav-link">In House Interface</Link></li>
                    <li><Link to={'/admin'} className="nav-link">Admin</Link></li>
                    <li><Link to={'/createorders'} className="nav-link">Create Orders</Link></li>

                    <li onClick={() => this.logout()}><Link to={'/'} className="nav-link">Logout</Link></li>
                    

                  </ul>
                </nav>

                <Switch>
                  <Route exact path="/" component={Welcome} />
                  <Route exact path="/quotesystem" component={QuoteSystem} />
                  <Route exact path="/admin" component={Admin} />
                  <Route exact path="/inhouse" component={InHouse} />
                  <Route exact path="/createorders" component={CreateOrders} />
                  <Route component={Welcome} />
                </Switch>

              </div>
            </Router>
          </React.Fragment> :

          <Router>
            <div>

              <Switch>
                <Route path="/" component={Login} />
                <Route component={Login} />

              </Switch>
            </div>
          </Router>}


      </React.Fragment>
    );
  }
}


function mapStateToProps(state) {
  return {
    quotes: state.quoteReducer.quotes,
    associates: state.associateReducer.associates,
    auth: state.authReducer.auth,
    user: state.authReducer.associateLoggedIn
  };
}


const mapDispatchToProps = dispatch => ({
  getPageLoad: () => dispatch(getPageLoad()),
  getAssociates: () => dispatch(getAssociates()),
  dispatch
})

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(App);
