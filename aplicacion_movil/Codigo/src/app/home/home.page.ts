import { Component} from '@angular/core';
import { GoogleMapsModule } from '@angular/google-maps';
import {AngularFireDatabase} from '@angular/fire/compat/database';
import { HttpClient } from '@angular/common/http';
import { Observable, catchError, map, of } from 'rxjs';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})

export class HomePage{

  apiLoaded: Observable<boolean>;
  latitude: number;
  longitude: number;
  markerPosition: google.maps.LatLngLiteral;
  center: google.maps.LatLngLiteral = {lat: 4.666673, lng:-74.085248};
  markerOptions: google.maps.MarkerOptions = {draggable: false};
  zoom = 10;

  constructor(private db: AngularFireDatabase, httpClient: HttpClient) {
  //Trae los datos de Firebase y los guarda temporalmente en latitude y longitude
  const gpsRef = this.db.database.ref('GPS');
  gpsRef.on('value', snapshot => {
    const gpsData = snapshot.val();
    if (gpsData) {
      this.latitude = gpsData.f_latitude;
      this.longitude = gpsData.f_longitude;
      this.center = {lat: this.latitude, lng: this.longitude};
      this.markerPosition = {lat: this.latitude, lng: this.longitude};
      this.zoom = 20;
    }
  });
  //Carga el Mapa
  this.apiLoaded = httpClient.jsonp('https://maps.googleapis.com/maps/api/js?key=AIzaSyBPsDYHOlTPse4dtzDI58PjZvMl9eWLwFM', 'callback')
  .pipe(
    map(() => true),
    catchError(() => of(false)),
  );
  
}

}
