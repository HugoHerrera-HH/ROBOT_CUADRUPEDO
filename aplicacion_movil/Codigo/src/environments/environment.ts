/*
  Se importa para ambientes de desarrollo la configuración de Firebase y de Google Maps
  con sus respectivas Keys.
*/
export const environment = {
  production: false,
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


/*
 * For easier debugging in development mode, you can import the following file
 * to ignore zone related error stack frames such as `zone.run`, `zoneDelegate.invokeTask`.
 *
 * This import should be commented out in production mode because it will have a negative impact
 * on performance if an error is thrown.
 */
// import 'zone.js/plugins/zone-error';  // Included with Angular CLI.
