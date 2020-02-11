import axios from 'axios';

const initialState = {
  associates: []
};

function associateReducer(state = initialState, action) {

  switch (action.type) {
    case 'SET_ASSOCIATES':
      return{
        ...state,
        associates: action.payload.data
      }
    case 'ADD_COMMISSON':
      let newState = { ...state };
      newState.associates.forEach((associate, i) => {
        if (associate.id === action.payload.id) {
          newState.associates[i].commission += action.payload.commission
        }
      });
      return {
        ...state,
        associates: newState.associates
      };
    case 'EDIT_ASSOCIATE':

      let newerState = { ...state };
      newerState.associates.forEach((associate, i) => {
        if (associate.id === action.payload.id) {
          newerState.associates[i] = action.payload
        }
      });

      axios.put('http://localhost:8080/associates', action.payload)
      .then(function (response) {
        console.log(response);
      })
      .catch(function (error) {
        console.log(error);
      });

      console.log(newerState.associates);
      return {
        ...state,
        associates: newerState.associates
      };
    case 'ADD_ASSOCIATE':
      let oldState = {...state}
      oldState.associates.push(action.payload)

      axios.post('http://localhost:8080/associates', action.payload)
      .then(function (response) {
        console.log(response);
      })
      .catch(function (error) {
        console.log(error);
      });

      return {
        ...state,
        associates: oldState.associates
      };
    default:
      return state;
  }
}

export default associateReducer;