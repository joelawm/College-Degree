import React, { Component } from "react";
import { connect } from "react-redux";

class Login extends Component {
  constructor(props) {
    super(props);

    this.state = {
      id: "",
      password: "",
      error: false
    };
  }

  componentDidUpdate() {
    if (this.state.id === "") {
      if (this.props.associates[0])
        this.setState({
          id: this.props.associates[0].id
        })
    }
  }


  componentMount() {
    if (this.state.id === "") {
      this.setState({
        id: this.props.associates[0].id
      })
    }
  }

  idChange(e) {
    console.log(e);

    this.setState({
      id: e.target.value
    });
  }

  passwordChange(e) {
    this.setState({
      password: e.target.value
    });
  }
  login() {


    let obj = this.props.associates.find(o => o.id === this.state.id);


    if (obj && obj.password === this.state.password) {


      this.props.dispatch({
        type: "SUCCESS",
        payload: obj
      });
      this.setState({
        error: false
      })

    } else {
      this.props.dispatch({
        type: "DENY"
      });
      this.setState({
        error: true
      })


    }
  }
  render() {

    if (!this.props.associates[0]) {
      return (
        <div class="text-center vh-100">
          <div class="spinner-border text-light mt-5" role="status">
            <span class="sr-only">Loading...</span>
          </div>
        </div>)
    }

    if (this.state.id === "") {
      this.setState({
        id: this.props.associates[0].id
      })
    }



    return (
      <div className="container-fluid">
        <div className="row">
          <div className="col-10 col-lg-6 mx-auto text-center mt-5">
            <h2>LOGIN TO ASSOCIATE ACCOUNT</h2>
            <form className="d-md-block mx-sm-2 mx-md-5" id="login">
              <div className="form-group">
                <label for="exampleFormControlInput1">ID</label>
                <select
                  class="form-control"
                  id="exampleFormControlSelect1"
                  onChange={e => this.idChange(e)}
                >
                  {this.props.associates.map((value, index) => {
                    return <option>{value.id}</option>
                  })}
                </select>
              </div>
              <div className="form-group">
                <label for="exampleFormControlInput1">Password</label>
                <input
                  type="password"
                  class="form-control"
                  id="exampleInputPassword1"
                  placeholder="Password"
                  onChange={e => this.passwordChange(e)}
                />
              </div>
            </form>

            <div className="submitButton" onClick={() => this.login()}>
              Login
        </div>

            {this.state.error &&
              <div className="ml-3" style={{ color: 'red' }}>
                Incorrect user ID and password combination
      </div>}
          </div>
        </div>
      </div>

    );
  }
}

function mapStateToProps(state) {
  return {
    associates: state.associateReducer.associates,
    auth: state.authReducer.auth
  };
}

export default connect(mapStateToProps)(Login);
