// Add the text to the <span>...<span> element in the element with id=table-title
function updateTableTitle(title) {
  newTitle = document.querySelector("#table-title span");
  newTitle.innerText = title;
}

// Add the given <tr>...</tr> element to the table body element with id=rows
function addRowToTable(row) {
  let rows = document.querySelector("#rows");
  rows.appendChild(row);
}

// Remove all content from the table body element with id=rows
function clearAllTableRows() {
  let rows = document.querySelector("#rows");
  while (rows.lastElementChild) {
    rows.removeChild(rows.lastElementChild);
  }
}

// Creates and returns new table row <tr> element with the specified id value.
function createTableRow(id) {
  let tr = document.createElement("tr");
  tr.id = id;
  return tr;
}

// Given a child element, create a <td> and add this child to it. Return the <td>.
function createTableCell(child) {
  let td = document.createElement("td");
  td.appendChild(child);
  return td;
}

// Wraps a child element in a <td>...</td> and adds it to the table row
function addContentToRow(child, row) {
  row.appendChild(createTableCell(child));
}

// Given a URL src string and alt text string, create an <img> element and return:
function createImg(src, alt) {
  let img = document.createElement("img");
  img.src = src;
  img.alt = alt;
  return img;
}

// Given a string of text, create and return a TextNode
function createText(text) {
  return document.createTextNode(text);
}

// create and return an anchor element.
function createAnchor(href, innerContent) {
  let anchor = document.createElement("a");
  anchor.href = href;
  anchor.appendChild(innerContent);
  return anchor;
}

// Return a proper time element with its dateTime property set:
function createTime(formatted) {
  let time = document.createElement("time");
  formatted = formatted.replace(/(\d{1,2})\/(\d{1,2})\/(\d{4})/, "$3-$2-$1");
  time.dateTime = formatted;
  time.appendChild(createText(formatted.replace(/\//g, "-")));
  return time;
}

// Given a boolean value (true/false) return a string "Yes" or "No"
function toYesNo(value) {
  let result;
  if (value) {
    result = "Yes";
  } else {
    result = "No";
  }
  return result;
}

// Converts an Observation object into DOM nodes that produce the following HTML:
function buildRowForObservation(observation) {
  // 1. Create the row for this observation with correct id: <tr id="67868131">...</tr>
  const row = createTableRow(observation.id);

  // 2. Create the photo, make it a link to the observation page, and put it in the first cell
  const photo = createImg(observation.photoUrl, observation.name);

  //3. <a href="https://www.inaturalist.org/observations/67868131">...</a>
  const observationLink = createAnchor(observation.uri, photo);
  addContentToRow(observationLink, row);

  // 4. Create the date and put in the second cell
  const time = createTime(observation.date.toLocaleDateString());

  addContentToRow(time, row);

  // 5. Create the name with a link to its Wikipedia page in the third cell
  const name = createText(observation.name);
  const wikipediaLink = createAnchor(observation.wikipediaUrl, name);
  addContentToRow(wikipediaLink, row);

  // 4-9. Create a Yes/No text cell for each of the characteristics in the array
  ["isEndangered", "isNative", "isThreatened", "isIntroduced"].forEach(
    (characteristic) => {
      const yesNoText = toYesNo(observation[characteristic]);
      const yesNoNode = createText(yesNoText);
      addContentToRow(yesNoNode, row);
    }
  );
  console.log({ row });
  return row;
}
