import React from 'react';
import { Outlet } from "react-router-dom";
import styles from "./BaseLayout.module.css";

function BaseLayout() {
  return (
    <>
      <div className={styles.base}>
        <Outlet />
      </div>
    </>
  );
}

export default BaseLayout;
