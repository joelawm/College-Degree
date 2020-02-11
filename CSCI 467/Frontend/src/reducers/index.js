import {combineReducers} from 'redux';
import quoteReducer from './quoteReducer';
import associateReducer from './associateReducer';
import authReducer from './authReducer';



const rootReducer = combineReducers({
    quoteReducer:quoteReducer,
    associateReducer:associateReducer,
    authReducer:authReducer
});

export default rootReducer;