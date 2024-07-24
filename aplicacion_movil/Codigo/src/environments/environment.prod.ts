/*
  Se importa para ambientes de producción la configuración de Firebase y de Google Maps
  con sus respectivas Keys.
*/
export const environment = {
  production: true,
  firebaseConfig: {
    apiKey: "AIzaSyBHE_iD9_KJ9BJClYZhy7YmCfhnxfgeueI",
    authDomain: "esp8266-gps-eee74.firebaseapp.com",
    databaseURL: "https://esp8266-gps-eee74-default-rtdb.firebaseio.com/",
    projectId: "esp8266-gps-eee74",
    storageBucket: "esp8266-gps-eee74.appspot.com",
    messagingSenderId: "203726153205",
    appId: "1:203726153205:web:df90e830579d2e48deecbc"
  },
  keys: {
  googleMaps: 'AIzaSyBPsDYHOlTPse4dtzDI58PjZvMl9eWLwFM'
   }
};

