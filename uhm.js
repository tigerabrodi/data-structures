function fetchUserData(id) {
  const response = fetch(`https://api.example.com/users/${id}`);
  return response.json();
}

function formatBirthDate(dateString) {
  const birthDate = new Date(dateString);
  return `${
    birthDate.getMonth() + 1
  }/${birthDate.getDate()}/${birthDate.getFullYear()}`;
}

function displayUserData(userData) {
  const formattedDate = formatBirthDate(userData.birthDate);
  console.log(`User: ${userData.name}, Birthdate: ${formattedDate}`);
}

// Using the refactored functions
const user = fetchUserData(1);
displayUserData(user);
