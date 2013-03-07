-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Mar 07, 2013 at 01:43 PM
-- Server version: 5.5.28
-- PHP Version: 5.4.6-1ubuntu1.1

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `bakaplan`
--

-- --------------------------------------------------------

--
-- Table structure for table `ClassDetails`
--

CREATE TABLE IF NOT EXISTS `ClassDetails` (
  `SNo` int(255) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(255) NOT NULL,
  `ClassName` varchar(50) NOT NULL,
  `TotalSubjects` int(30) NOT NULL,
  `SubjectName` varchar(100) NOT NULL,
  `SubjectCode` varchar(100) NOT NULL,
  UNIQUE KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ProjectName`
--

CREATE TABLE IF NOT EXISTS `ProjectName` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(255) NOT NULL,
  `ProjectName` varchar(30) NOT NULL,
  PRIMARY KEY (`ProjectID`),
  UNIQUE KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `TotalClasses`
--

CREATE TABLE IF NOT EXISTS `TotalClasses` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(255) NOT NULL,
  `TotalClasses` int(30) NOT NULL,
  PRIMARY KEY (`SNo`),
  UNIQUE KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `User`
--

CREATE TABLE IF NOT EXISTS `User` (
  `SNo` int(50) NOT NULL,
  `EmailID` varchar(30) NOT NULL,
  `Password` varchar(8) NOT NULL,
  PRIMARY KEY (`EmailID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `User`
--

INSERT INTO `User` (`SNo`, `EmailID`, `Password`) VALUES
(2, 'mandy@gmail.com', '123456'),
(1, 'meghasimak@gmail.com', 'password');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
