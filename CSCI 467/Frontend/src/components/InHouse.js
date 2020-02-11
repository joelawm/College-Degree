import React, { Component } from "react";
import { withRouter } from "react-router";
import { connect } from "react-redux";
import pencil from "../images/pencil.png";
import axios from "axios";
import reset from "../images/reset.png";

class InHouse extends Component {
  constructor(props) {
    super(props);

    this.state = {
      selectedQuote: {},
      customers: [],
      currentQuotes: null
    };
  }

  componentDidUpdate(prevProps, prevState) {
    console.log(this.props.quotes);
    console.log(prevProps.quotes);

    if (prevProps.quotes !== this.props.quotes) {
      this.setState({
        currentQuotes: this.props.quotes
      });
    }
  }

  changeFilter(type, e) {
    let newQuotes = this.props.quotes.filter(function(el) {
      return type === "desc"
        ? el[type].indexOf(e.target.value) !== -1
        : el[type] === e.target.value;
    });

    console.log(newQuotes);

    this.setState({
      currentQuotes: newQuotes
    });
  }

  componentDidMount() {
    axios
      .get("http://localhost:8080/users")
      .then(response => {
        this.setState({
          customers: response.data
        });
      })
      .catch(function(error) {
        console.log(error);
      });
  }

  changeSelectedQuote(quote) {
    this.setState({
      selectedQuote: quote
    });
  }

  valueChange(e, type) {
    this.setState({
      selectedQuote: {
        ...this.state.selectedQuote,
        [type]:
          type === "price"
            ? parseFloat(e.target.value)
            : type === "complete"
            ? e.target.checked
            : e.target.value
      }
    });
  }

  removeQuote(quote) {
    var txt;
    var r = window.confirm(
      "Are you sure you want to delete quote id: " + quote._id
    );
    if (r == true) {
      this.props.dispatch({
        type: "REMOVE_QUOTE",
        payload: quote
      });
    }
  }

  saveChanges() {
    let test = false;
    Object.keys(this.state.selectedQuote).map((key, index) => {
      if (
        this.state.selectedQuote[key] === "" ||
        (key === "price" && isNaN(this.state.selectedQuote[key]))
      ) {
        console.log(this.state.selectedQuote[key]);
        test = true;
      }
    });

    if (test) {
      window.alert("Error Changing Quote.");
      return;
    }

    let check = document.getElementById("sanctionCheck");

    if (check) {
      check.click();
    }

    let newArray = this.state.customers.filter(el => {
      return el.name === this.state.selectedQuote.name;
    });

    let newObj = { ...this.state.selectedQuote };
    if (newArray[0]) {
      newObj.custid = newArray[0].id;
    }

    this.props.dispatch({
      type: "EDIT_QUOTE",
      payload: newObj
    });

    this.setState({
      selectedQuote: {}
    });
  }

  render() {
    if (this.state.currentQuotes === null) {
      this.setState({
        currentQuotes: this.props.quotes
      });
    }
    if (!this.state.customers[0] || !this.props.quotes[0]) {
      return (
        <div class="text-center vh-100">
          <div class="spinner-border text-light mt-5" role="status">
            <span class="sr-only">Loading...</span>
          </div>
        </div>
      );
    }

    let quotes = this.state.currentQuotes;

    quotes.sort(function(a, b) {
      return a.id - b.id;
    });

    return (
      <div className="container-fluid">
        <div className="row">
          <div className="col-12 text-center">
            <h2 className="mt-3">Retrieve, Edit, and Sanction Quotes</h2>
            <h3 className="mt-3">Filter Quotes</h3>
            <img
              className="mb-2"
              src={reset}
              style={{ width: "30px" }}
              onClick={() =>
                this.setState({ currentQuotes: this.props.quotes })
              }
            />
            <div className="d-flex justify-content-center">
              Customer Name:
              <select
                class="form-control ml-2 "
                id="exampleFormControlSelect1"
                onChange={e => this.changeFilter("name", e)}
                style={{ width: "250px" }}
                value= 'Select customer' selected
              >
                {this.state.customers.map((value, index) => {
                  return <option>{value.name}</option>;
                })}
              </select>
            </div>

            <div className="d-flex justify-content-center">
              <label for="exampleFormControlInput1">Description:</label>
              <textarea
                style={{ width:'250px' }}
                onChange={e => this.changeFilter("desc", e)}
                className="form-control ml-2"
                id="exampleFormControlTextarea1"
                rows="1"
                placeholder="Enter quote description"
              ></textarea>
            </div>

            <table class="table table-striped mt-5">
              <thead class="thead-light">
                <tr>
                  <th scope="col">Edit</th>
                  <th scope="col">Name</th>
                  <th scope="col">Desc.</th>
                  <th scope="col">Price</th>
                  <th scope="col">Email</th>
                  <th scope="col">Complete</th>
                  <th scope="col">Remove</th>
                </tr>
              </thead>
              <tbody>
                {quotes.map((quote, i) => {
                  return (
                    <tr>
                      <th className="truncate" scope="row">
                        #{quote.id}{" "}
                        {!quote.complete && (
                          <img
                            className="imghover"
                            data-toggle="modal"
                            data-target="#exampleModal"
                            onClick={() => this.changeSelectedQuote(quote)}
                            style={{ width: "20px" }}
                            src={pencil}
                          />
                        )}
                      </th>
                      <td className="truncate">{quote.name}</td>
                      <td className="truncate">{quote.desc}</td>
                      <td className="truncate">${quote.price}</td>
                      <td className="truncate">{quote.email}</td>
                      <td className="truncate">
                        {quote.complete ? "Yes" : "No"}
                      </td>
                      <td
                        onClick={() => this.removeQuote(quote)}
                        className="truncate"
                      >
                        X
                      </td>
                    </tr>
                  );
                })}
              </tbody>
            </table>

            <div
              class="modal fade"
              id="exampleModal"
              tabindex="-1"
              role="dialog"
              aria-labelledby="exampleModalLabel"
              aria-hidden="true"
            >
              <div class="modal-dialog" role="document">
                <div class="modal-content">
                  <div class="modal-header">
                    <h5 class="modal-title" id="exampleModalLabel">
                      Edit Quote
                    </h5>
                    <button
                      type="button"
                      class="close"
                      data-dismiss="modal"
                      aria-label="Close"
                    >
                      <span aria-hidden="true">&times;</span>
                    </button>
                  </div>
                  <div class="modal-body">
                    <form class="">
                      <div className="mb-2 ml-2 form-group">
                        Name:{" "}
                        <select
                          id="exampleFormControlSelect1"
                          onChange={e => this.valueChange(e, "name")}
                          value={this.state.selectedQuote.name}
                        >
                          {this.state.customers.map((value, index) => {
                            return <option>{value.name}</option>;
                          })}
                        </select>
                      </div>

                      <div className="mb-2 ml-2 form-group">
                        Price:{" "}
                        <input
                          onChange={e => this.valueChange(e, "price")}
                          type="number"
                          value={this.state.selectedQuote.price}
                        />
                      </div>
                      <div className="mb-2 ml-2 form-group">
                        Desc:{" "}
                        <input
                          onChange={e => this.valueChange(e, "desc")}
                          type="text"
                          value={this.state.selectedQuote.desc}
                        />
                      </div>

                      <div class="form-check ml-2 form-group">
                        <input
                          class="form-check-input"
                          onChange={e => this.valueChange(e, "complete")}
                          type="checkbox"
                          value=""
                          id="sanctionCheck"
                        />
                        <label class="form-check-label" for="defaultCheck1">
                          Sanction Quote
                        </label>
                      </div>
                    </form>
                  </div>
                  <div class="modal-footer">
                    <button
                      type="button"
                      class="btn btn-secondary"
                      data-dismiss="modal"
                    >
                      Close
                    </button>
                    <button
                      onClick={() => this.saveChanges()}
                      data-dismiss="modal"
                      type="button"
                      class="btn btn-primary"
                    >
                      Save changes
                    </button>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

function mapStateToProps(state) {
  return {
    quotes: state.quoteReducer.quotes
  };
}

export default connect(mapStateToProps)(InHouse);
