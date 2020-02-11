import {createStore} from 'redux';
import quoteReducer from './reducers/quoteReducer';

export default createStore(
    quoteReducer
);