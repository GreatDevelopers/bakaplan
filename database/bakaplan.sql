-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Mar 11, 2013 at 10:27 AM
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
  `ProjectID` int(255) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(50) NOT NULL,
  `ProjectName` varchar(30) NOT NULL,
  PRIMARY KEY (`ProjectID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Session`
--

CREATE TABLE IF NOT EXISTS `Session` (
  `SNo` int(25) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(150) NOT NULL,
  `SessionID` varchar(250) NOT NULL,
  PRIMARY KEY (`SNo`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=14 ;

--
-- Dumping data for table `Session`
--

INSERT INTO `Session` (`SNo`, `EmailID`, `SessionID`) VALUES
(9, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fee9bf5b556828372c09399e766712873'),
(10, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fffb51880e37fbac1c20289a86c250fe6'),
(11, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fffb51880e37fbac1c20289a86c250fe6'),
(12, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fffb51880e37fbac1c20289a86c250fe6'),
(13, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fffb51880e37fbac1c20289a86c250fe6');

-- --------------------------------------------------------

--
-- Table structure for table `TotalClasses`
--

CREATE TABLE IF NOT EXISTS `TotalClasses` (
  `ProjectID` int(255) NOT NULL,
  `TotalClasses` int(30) NOT NULL,
  PRIMARY KEY (`ProjectID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `User`
--

CREATE TABLE IF NOT EXISTS `User` (
  `SNo` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(30) NOT NULL,
  `Password` varchar(250) NOT NULL,
  PRIMARY KEY (`EmailID`),
  KEY `SNo` (`SNo`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=9 ;

--
-- Dumping data for table `User`
--

INSERT INTO `User` (`SNo`, `EmailID`, `Password`) VALUES
(8, 'abc@123.com', 'e10adc3949ba59abbe56e057f20f883e'),
(7, 'mandeep@gmail.com', '202cb962ac59075b964b07152d234b70');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
