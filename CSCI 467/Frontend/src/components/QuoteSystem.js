import React, { Component } from "react";
import axios from "axios";
import { connect } from 'react-redux';
import '../App.css';

class QuoteSystem extends Component {
  constructor(props) {
    super(props);

    this.state = {
      customerName: "",
      description: "",
      price: "",
      customers: [],
      email: "",
      hasError: false
    };
  }

  componentDidMount() {
    axios
      .get("http://localhost:8080/users")
      .then(response => {
        this.setState({
          customers: response.data
        });
      })
      .catch(function (error) {
        console.log(error);
      });
  }
  nameChange(e) {
    this.setState({
      customerName: e.target.value
    });
  }

  descChange(e) {
    this.setState({
      description: e.target.value
    });
  }

  priceChange(e) {
    this.setState({
      price: e.target.value
    });
  }

  emailChange(e) {
    this.setState({
      email: e.target.value
    });
  }

  addQuote() {
    if (this.state.price === "" || this.state.email === "" || this.state.description === "" || this.state.customerName === "") {
      this.setState({
        hasError: true
      })
      return
    } else {
      this.setState({
        hasError: false
      })
    }
    let newArray = this.state.customers.filter( (el) => {
      return el.name === this.state.customerName
    });
    this.props.dispatch({
      type: "ADD_QUOTE",
      payload: {
        name: this.state.customerName,
        desc: this.state.description,
        price: typeof this.state.price == "string" ? parseFloat(this.state.price) : this.state.price,
        email: this.state.email,
        id: this.props.quotes.length + 1,
        custid: newArray[0] ? newArray[0].id : 0,
        processed: false
      }
    });
    this.setState({
      customerName: "",
      description: "",
      price: "",
      email: ""
    })
    document.getElementById("quoteForm").reset();
  }

  componentDidUpdate(prevProps, prevState) {
    if (prevState.customers !== this.state.customers) {
      this.setState({
        customerName: this.state.customers[0].name
      });
    }
  }
  render() {
    return (
      <React.Fragment>
        <div className="container-fluid">
          <div className="row justify-content-center">
            <div className="col-8  col-lg-5">
              <h2 className="mx-5 mb-5 mt-3">Enter new quotes</h2>
              <form className="d-md-block mx-sm-2 mx-md-5" id="quoteForm">
                <div className="form-group">
                  <label for="exampleFormControlInput1">Customer Name</label>
                  <select
                    class="form-control"
                    id="exampleFormControlSelect1"
                    onChange={e => this.nameChange(e)}
                  >
                    {this.state.customers.map((value, index) => {
                    

                      return <option>{value.name}</option>;
                    })}
                  </select>
                </div>
                <div className="form-group">
                  <label for="exampleFormControlInput1">Description</label>
                  <textarea
                    onChange={e => this.descChange(e)}
                    className="form-control"
                    id="exampleFormControlTextarea1"
                    rows="1"
                    placeholder="Enter quote description"
                  ></textarea>
                </div>
                <div className="form-group">
                  <label for="exampleFormControlInput1">Price</label>
                  <input
                    onChange={e => this.priceChange(e)}
                    type="number"
                    class="form-control"
                    id="exampleInputEmail1"
                    aria-describedby="emailHelp"
                    placeholder="0"
                  />
                </div>
                <div className="form-group">
                  <label for="exampleFormControlInput1">Email</label>
                  <input
                    onChange={e => this.emailChange(e)}
                    type="email"
                    class="form-control"
                    id="exampleInputEmail1"
                    aria-describedby="emailHelp"
                    placeholder="Enter email"
                  />
                </div>
                <div className="submitButton" onClick={() => { this.addQuote() }}>SUBMIT QUOTE INTO SYSTEM</div>
                {this.state.hasError && <div style={{ color: 'red' }} >ERROR: please fill out all fields</div>}
              </form>

            </div>
          </div>
        </div>


      </React.Fragment>
    );
  }
}


function mapStateToProps(state) {
  return {
    quotes: state.quoteReducer.quotes,
  };
}

export default connect(
  mapStateToProps
)(QuoteSystem);
