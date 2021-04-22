// Author: Professor David  Humphrey
////////////////////////////////////////

function SimpleMap(id, lat = 43.7955, lng = -79.3496, zoomLevel = 15) {
  const map = L.map(id, { scrollWheelZoom: false }).setView(
    [lat, lng],
    zoomLevel
  );
  L.tileLayer(
    "https://{s}.basemaps.cartocdn.com/rastertiles/voyager_labels_under/{z}/{x}/{y}{r}.png",
    {
      attribution:
        '&copy; <a href="https://www.openstreetmap.org/copyright" target="_blank" rel="noopener noreferrer">OpenStreetMap</a> contributors &copy; <a href="https://carto.com/attributions" target="_blank" rel="noopener noreferrer">CARTO</a>',
      maxZoom: 19,
    }
  ).addTo(map);

  // Create a cluster marker group, so multiple markers close to each other are joined.
  const markers = L.markerClusterGroup();
  map.addLayer(markers);

  // Store these properties on the instance
  this.map = map;
  this.markers = markers;
}

/**
 * Add a clickable marker and popup to the map that displays the given info.
 *
 * @param {Object} observation the observation for which we want to add a marker
 */
SimpleMap.prototype.addObservation = function (observation) {
  const { id, coords, name, photoUrl } = observation;
  const [lng, lat] = coords;

  function createImgHtml(url, alt) {
    return `<img src="${url}" alt=${alt}>`;
  }

  const content = name || "Unknown";
  const imgHtml = createImgHtml(photoUrl, name);
  const html = `<p class="marker-text"><a href="#${id}">${content}</a></p><p class="marker-text">${imgHtml}</p>`;

  this.markers.addLayer(L.marker([lat, lng]).bindPopup(html, { minWidth: 75 }));
};

/**
 * Clear all markers from the map.
 */
SimpleMap.prototype.clear = function () {
  const map = this.map;
  map.removeLayer(this.markers);
  this.markers = L.markerClusterGroup();
  map.addLayer(this.markers);
};
