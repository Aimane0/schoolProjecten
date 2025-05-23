/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ["./src/**/*.{js,jsx,ts,tsx}"],
  theme: {
    extend: {
      colors: {
        navy: '#001f6f',
      },
      animation: {
        spin: "spin 2s linear infinite",
      },
    },
  },
  plugins: [],
};
