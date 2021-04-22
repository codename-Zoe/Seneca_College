/*******************************************************************************
 * Problem 1: replace all internal whitespace in a string value with dashes ('-'),
 * and make it UPPERCASE.
 ******************************************************************************/

function kebab(value) {
  value = value.toUpperCase().trim();
  value = value.replace(/[^A-Z-]+/g, '-');
  return value;
}

/*******************************************************************************
 * Problem 2: create an HTML <img> element for the given url and alt text.
 ******************************************************************************/

function createImg(src, alt, width) {
  src = src.trim();
  alt = alt.trim();

  if (!isFinite(width)) {
    return '<img src="' + src + '" alt="' + alt + '">';
  } else if (isFinite(width)) {
    return '<img src="' + src + '" alt="' + alt + '" ' + 'width="' + width + '">';
  }
}

/*******************************************************************************
 * Problem 3: extract Date from date string
 ******************************************************************************/

function parseDateString(value) {
  let date = new Date();
  if (/[^0-9-]/g.test(value) || value.length !== 10) {
    throw new Error('Error!');
  }
  value = value.split('-');
  let year = value[0];
  let month = value[2];
  let day = value[1];
  if (year.length === 4 && month.length === 2 && day.length === 2) {
    if (month > 12) {
      let temp = day;
      day = month;
      month = temp;
    }
    date.setFullYear(year);
    date.setMonth(month - 1);
    date.setDate(day);
  }
  return date;
}

/*******************************************************************************
 * Problem 4: convert Date to date string with specified format.
 ******************************************************************************/

function toDateString(value) {
  let year = value.getFullYear();
  let month = ('00' + (value.getMonth() + 1)).slice(-2);
  let day = ('00' + value.getDate()).slice(-2);
  return year + '-' + day + '-' + month;
}

/*******************************************************************************
 * Problem 5: validate a coordinate
 ******************************************************************************/

function validateCoord(lat, lng) {
  let validlat = false;
  let validlng = false;
  if (-90 <= lat && lat <= 90) {
    validlat = true;
  }
  if (-180 <= lng && lng <= 180) {
    validlng = true;
  }
  if (validlat && validlng) {
    return true;
  } else {
    return false;
  }
}

/*******************************************************************************
 * Problem 6, Part 1: format a coordinate as a string
 ******************************************************************************/

function formatCoord(lat, lng, includeBrackets) {
  let result;
  if (validateCoord(lat, lng)) {
    if (includeBrackets) {
      result = '[' + lat + ',' + lng + ']';
    } else {
      result = lat + ',' + lng;
    }
    return result;
  }
  throw new Error('Error!');
}

/*******************************************************************************
 * Problem 6, Part 2: format any number of coordinates as a string
 ******************************************************************************/

function formatCoords(...values) {
  let j = 0;
  let str = [];
  let string = '';
  let result = '';
  if (values.length % 2 === 0) {
    for (let i = 0; i < values.length; i++) {
      if (i % 2 === 0) {
        str[j] = formatCoord(values[i], values[i + 1], true);
        j++;
      }
    }
    for (let i = 0; i < j; i++) {
      string += str[i] + ', ';
    }
    string = string.slice(0, -2);
    result = '[' + string + ']';
  } else {
    throw new Error('Error!');
  }
  return result;
}

/*******************************************************************************
 * Problem 7: determine MIME type from filename extension
 ******************************************************************************/

function mimeFromFilename(filename) {
  if (filename.endsWith('.html') || filename.endsWith('.htm')) {
    return 'text/html';
  } else if (filename.endsWith('.css')) {
    return 'text/css';
  } else if (filename.endsWith('.js')) {
    return 'text/javascript';
  } else if (filename.endsWith('.jpg') || filename.endsWith('.jpeg')) {
    return 'image/jpeg';
  } else if (filename.endsWith('.gif')) {
    return 'image/gif';
  } else if (filename.endsWith('.bmp')) {
    return 'image/bmp';
  } else if (filename.endsWith('.ico') || filename.endsWith('.cur')) {
    return 'image/x-icon';
  } else if (filename.endsWith('.png')) {
    return 'image/png';
  } else if (filename.endsWith('.svg')) {
    return 'image/svg+xml';
  } else if (filename.endsWith('.webp')) {
    return 'image/webp';
  } else if (filename.endsWith('.mp3')) {
    return 'audio/mp3';
  } else if (filename.endsWith('.wav')) {
    return 'audio/wav';
  } else if (filename.endsWith('.mp4')) {
    return 'video/mp4';
  } else if (filename.endsWith('.webm')) {
    return 'video/webm';
  } else if (filename.endsWith('.json')) {
    return 'application/json';
  } else {
    return 'application/octet-stream';
  }
}

/*******************************************************************************
 * Problem 8, Part 1: generate license text and link from license code.
 ******************************************************************************/

function generateLicenseLink(licenseCode) {
  let url = 'https://creativecommons.org/licenses/';
  if (typeof licenseCode === 'string' && licenseCode.indexOf('CC', 0) !== -1) {
    licenseCode = licenseCode.replace('CC-', '').toLocaleLowerCase();
    url = url + licenseCode + '/4.0/';

    switch (licenseCode) {
      case 'by':
        return '<a href="' + url + '">' + 'Creative Commons Attribution License</a>';
      case 'by-nc':
        return '<a href="' + url + '">' + 'Creative Commons Attribution-NonCommercial License</a>';
      case 'by-sa':
        return '<a href="' + url + '">' + 'Creative Commons Attribution-ShareAlike License</a>';
      case 'by-nd':
        return '<a href="' + url + '">' + 'Creative Commons Attribution-NoDerivs License</a>';
      case 'by-nc-sa':
        return (
          '<a href="' +
          url +
          '">' +
          'Creative Commons Attribution-NonCommercial-ShareAlike License</a>'
        );
      case 'by-nc-nd':
        return (
          '<a href="' +
          url +
          '">' +
          'Creative Commons Attribution-NonCommercial-NoDerivs License</a>'
        );
    }
  } else {
    return '<a href="https://choosealicense.com/no-permission/">' + 'All Rights Reserved</a>';
  }
}

/*******************************************************************************
 * Problem 9 Part 1: create a pure Boolean true/false value from a dataset
 ******************************************************************************/

function pureBool(value) {
  let str1 = 'yes y true t';
  let str2 = 'no n false f';

  if (typeof value === 'string') {
    value = value.toLowerCase();
  }
  if (str1.includes(value) || value > 0) {
    return true;
  } else if (str2.includes(value) || value < 0) {
    return false;
  } else if (value === undefined || value === '' || value === null || typeof value === 'number') {
    return false;
  } else {
    throw new Error('invalid boolean value');
  }
}

/*******************************************************************************
 * Problem 9 Part 2: checking for all True or all False values in a normalized list
 ******************************************************************************/

function all() {
  let result = [];
  for (let i = 0; i < arguments.length; i++) {
    result[i] = pureBool(arguments[i]);
  }
  if (result.every((result) => result === true)) {
    return true;
  } else {
    return false;
  }
}

function none() {
  let result = [];
  for (let i = 0; i < arguments.length; i++) {
    result[i] = pureBool(arguments[i]);
  }
  if (result.every((result) => result === false)) {
    return true;
  } else {
    return false;
  }
}

/*******************************************************************************
 * Problem 10 - build a URL to query the iNaturalist Web API
 ******************************************************************************/

function buildUrl(q, perPage, order, license, lat, lng) {
  let prefix = 'https://api.inaturalist.org/v1/observations?';
  for (let i = 0; i < arguments.length; i++) {
    if (arguments[i]) {
      if (0 < perPage && perPage <= 200) {
        if (order === 'asc' || order === 'desc') {
          if (license) {
            if (validateCoord(lat, lng)) {
              q = 'q=' + q;
              perPage = '&per_page=' + perPage;
              order = '&order=' + order;
              license = '&license=' + license;
              lat = '&lat=' + lat;
              lng = '&lng=' + lng;
              return prefix + q + perPage + order + license + lat + lng;
            }
          }
        }
      }
    }
  }
  throw new Error('Error!');
}

// Our unit test files need to access the functions we defined
// above, so we export them here.
exports.kebab = kebab;
exports.createImg = createImg;
exports.parseDateString = parseDateString;
exports.toDateString = toDateString;
exports.validateCoord = validateCoord;
exports.formatCoord = formatCoord;
exports.formatCoords = formatCoords;
exports.mimeFromFilename = mimeFromFilename;
exports.generateLicenseLink = generateLicenseLink;
exports.pureBool = pureBool;
exports.all = all;
exports.none = none;
exports.buildUrl = buildUrl;
