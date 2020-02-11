const initialState = {
  auth: false,
  associateLoggedIn: {}
};

function authReducer(state = initialState, action) {
  switch (action.type) {
    case "SUCCESS":
      return {
        auth: true,
        associateLoggedIn: action.payload
      };
    case "DENY":
      return {
        auth: false,
        associateLoggedIn: {}
      };
    default:
      return state;
  }
}

export default authReducer;
