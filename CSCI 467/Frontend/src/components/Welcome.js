import React, { Component } from 'react'
import { connect } from "react-redux";

class Welcome extends Component {
    render() {
        return (
            <div className="container h-100">
                <div className="row ">
                    <h2 className=" col-12 mx-auto text-center mt-5">
                        Welcome, {this.props.user.name}
                    </h2>
                    <div className=" col-12 mx-auto text-center">
                        Associate ID: {this.props.user.id}
                    </div>
                    <div className=" col-12 mx-auto text-center">
                        Total Commision: ${this.props.user.commission}
                    </div>
                    <div className=" col-12 mx-auto text-center">
                        {this.props.user.admin ? 'You are an admin and have special privileges' : null}
                    </div>

                </div>
            </div>
        )
    }
}



function mapStateToProps(state) {
    return {
        user: state.authReducer.associateLoggedIn
    };
}

export default connect(
    mapStateToProps
)(Welcome);

