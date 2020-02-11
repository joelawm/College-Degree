import axios from 'axios';


const setQuotes = response => ({
    type: 'SET_QUOTES',
    payload: response
});

const setAssociates = response => ({
    type: 'SET_ASSOCIATES',
    payload: response
});

export function getPageLoad() {
	return function (dispatch) {
		axios({
			method: 'get',
			url: 'http://localhost:8080/quotes'
		})
			.then((response) => {
                console.log(response);
                
				dispatch(setQuotes(response))
			})
			.catch((error) => {
				//dispatch(errorHandlingRecentTransactionsDetailsList(error));
			});
	};
}

export function getAssociates() {
	return function (dispatch) {
		axios({
			method: 'get',
			url: 'http://localhost:8080/associates'
		})
			.then((response) => {
                console.log(response);
                
				dispatch(setAssociates(response))
			})
			.catch((error) => {
				//dispatch(errorHandlingRecentTransactionsDetailsList(error));
			});
	};
}

