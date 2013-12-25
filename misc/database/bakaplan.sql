-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Dec 26, 2013 at 01:04 AM
-- Server version: 5.5.31
-- PHP Version: 5.4.4-14+deb7u5

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `bp_empty`
--

-- --------------------------------------------------------

--
-- Table structure for table `ContactDetail`
--

CREATE TABLE IF NOT EXISTS `ContactDetail` (
  `ContactID` int(50) NOT NULL AUTO_INCREMENT,
  `Name` varchar(70) NOT NULL,
  `EmailID` varchar(100) NOT NULL,
  `Feedback` varchar(1500) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`ContactID`),
  UNIQUE KEY `ContactID` (`ContactID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Contact Form Detail or feedback form' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ProjectDetail`
--

CREATE TABLE IF NOT EXISTS `ProjectDetail` (
  `ProjectID` int(50) NOT NULL AUTO_INCREMENT,
  `UserID` int(50) NOT NULL,
  `ProjectName` varchar(100) NOT NULL COMMENT 'Name of project',
  `ProjectType` varchar(100) NOT NULL COMMENT 'New or existing project',
  `ProjectDetailType` varchar(100) NOT NULL COMMENT 'Spreadsheet or CSV or Manual entry',
  PRIMARY KEY (`ProjectID`),
  KEY `FK_ProjectDetail` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Project Detail given by user' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Registration`
--

CREATE TABLE IF NOT EXISTS `Registration` (
  `RegID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(50) NOT NULL,
  `RegKey` varchar(100) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`RegID`),
  UNIQUE KEY `RegID` (`RegID`,`EmailID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Registration table for BaKaPlan' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ResetPassword`
--

CREATE TABLE IF NOT EXISTS `ResetPassword` (
  `ResetID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(70) NOT NULL,
  `ResetKey` varchar(100) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`ResetID`),
  UNIQUE KEY `ResetID` (`ResetID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Rest Password Table for BaKaPlan' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `SessionDetail`
--

CREATE TABLE IF NOT EXISTS `SessionDetail` (
  `SessionID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(50) NOT NULL,
  `SessionKey` varchar(100) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`SessionID`),
  UNIQUE KEY `SessionID` (`SessionID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Session Detail for BaKaPlan' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `User`
--

CREATE TABLE IF NOT EXISTS `User` (
  `UserID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(70) NOT NULL,
  `Password` varchar(50) NOT NULL,
  PRIMARY KEY (`EmailID`),
  UNIQUE KEY `UserID` (`UserID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COMMENT='User Table for BaKaPlan' AUTO_INCREMENT=2 ;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `ProjectDetail`
--
ALTER TABLE `ProjectDetail`
  ADD CONSTRAINT `FK_ProjectDetail` FOREIGN KEY (`UserID`) REFERENCES `User` (`UserID`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
