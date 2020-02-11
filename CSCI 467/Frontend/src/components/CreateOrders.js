import React, { Component } from "react";
import { connect } from "react-redux";
import axios from "axios";
import $ from "jquery";
import cart from "../images/trolley.png";
import check from "../images/check.png";

class CreateOrders extends Component {
  processOrder(quote) {
    let url = "http://blitz.cs.niu.edu/PurchaseOrder/";

    let postData = {
      order: Math.random()
        .toString(36)
        .substr(2, 9),
      associate: this.props.associate.id,
      custid: quote.custid,
      amount: quote.price
    };

    let config = {};

    axios
      .post(url, postData, config)
      .then(res => {
        console.log(res);
        this.props.dispatch({
          type: "ADD_COMMISSON",
          payload: {
            id: this.props.associate.id,
            commission: (parseFloat(res.data.commission) / 100.0) * quote.price
          }
        });

        var s = new Date(res.data.timeStamp).toLocaleDateString("en-US");
        var t = new Date(res.data.timeStamp).toLocaleTimeString("en-US");

        window.alert(
          "Order " +
            res.data.order +
            " processed and commission of $" +
            ((parseFloat(res.data.commission) / 100.0) * quote.price).toFixed(
              2
            ) +
            " has been added to associate. Email has been sent to customer. Processed on " +
            s +
            " at " +
            t +
            " by " +
            this.props.associate.name
        );

        let newQuote = { ...quote };
        newQuote.processed = true;
        console.log(newQuote);

        this.props.dispatch({
          type: "EDIT_QUOTE",
          payload: newQuote
        });

        this.forceUpdate();
      })
      .catch(err => {
        window.alert("Error processing order.");
        console.log(err);
      });
  }

  componentDidMount() {}
  render() {
    let sanctionedQuotes = this.props.quotes.filter(function(quote) {
      return quote.complete;
    });
    console.log(sanctionedQuotes);

    return (
      <React.Fragment>
        <h2>Convert Sanctioned Quotes into Orders</h2>
        <table class="table table-striped mt-5">
          <thead class="thead-light">
            <tr>
              <th scope="col">Id</th>
              <th scope="col">Name</th>
              <th scope="col">Desc.</th>
              <th scope="col">Price</th>
              <th scope="col">Email</th>
              <th scope="col">Processed</th>
            </tr>
          </thead>
          <tbody>
            {sanctionedQuotes.map((quote, i) => {
              return (
                <tr>
                  <th className="truncate" scope="row">
                    #{quote.id}
                  </th>
                  <td className="truncate">{quote.name}</td>
                  <td className="truncate">{quote.desc}</td>
                  <td className="truncate">${quote.price.toFixed(2)}</td>
                  <td className="truncate">{quote.email}</td>
                  <td className="truncate">
                    {quote.processed ? (
                      <img style={{ width: "25px" }} src={check} />
                    ) : (
                      <img
                        onClick={() => this.processOrder(quote)}
                        style={{ width: "25px" }}
                        src={cart}
                      />
                    )}
                  </td>
                </tr>
              );
            })}
          </tbody>
        </table>
      </React.Fragment>
    );
  }
}

function mapStateToProps(state) {
  return {
    quotes: state.quoteReducer.quotes,
    associate: state.authReducer.associateLoggedIn
  };
}

export default connect(mapStateToProps)(CreateOrders);
