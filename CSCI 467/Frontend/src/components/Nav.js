import React, { Component } from 'react'
import { BrowserRouter as Router, Switch, Route, Link } from 'react-router-dom';
import InHouse from './InHouse'

export default class Navbar extends Component {

    

    render() {

        return (
            
            <nav class="navbar navbar-expand-lg navbar-light bg-light">
                <a class="navbar-brand" href="#">Navbar</a>
                <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarNav">
                    <ul class="navbar-nav">
                        <li class="nav-item active">
                            <a class="nav-link" href="#">Associate Quote System</a>
                        </li>
                        <li class="nav-item">
                            <Link to={'/inhouse'} className="nav-link">In-House Interface</Link>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="#">Create Orders</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="#">Admin</a>
                        </li>
                    </ul>
                </div>
            </nav>
        )
    }
}
